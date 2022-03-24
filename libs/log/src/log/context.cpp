//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/loop.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_const.hpp>
#include <fcppt/string.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/container/tree/make_pre_order.hpp>
#include <fcppt/log/const_level_stream_array_reference.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/find_child_const.hpp>
#include <fcppt/log/impl/find_or_create_child.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#if defined(ENABLE_THREADS)
#include <mutex>
#endif
#include <utility>
#include <fcppt/config/external_end.hpp>

struct fcppt::log::context::impl
{
  FCPPT_NONMOVABLE(impl);
public:
#if defined(ENABLE_THREADS)
  using mutex_type = std::mutex;
  using lock_guard = std::lock_guard<std::mutex>;
#else
  struct mutex_type {};
  struct lock_guard { explicit lock_guard(mutex_type) {} };
#endif

  impl(fcppt::log::optional_level const &, fcppt::log::level_stream_array &&);

  ~impl();

  [[nodiscard]] fcppt::reference<fcppt::log::detail::context_tree>
  find_location_impl(fcppt::log::location const &, lock_guard const &);

  [[nodiscard]] mutex_type &mutex();

  [[nodiscard]] fcppt::reference<fcppt::log::detail::context_tree const> root() const;

  [[nodiscard]] fcppt::log::const_level_stream_array_reference streams() const;
private:
  mutable mutex_type mutex_;

  fcppt::log::detail::context_tree tree_;

  fcppt::log::level_stream_array const streams_;
};

fcppt::log::context::context(
    fcppt::log::optional_level const &_root_level, fcppt::log::level_stream_array &&_streams)
    : impl_{fcppt::make_unique_ptr<impl>(_root_level, std::move(_streams))}
{
}

fcppt::log::context::~context() = default;

void fcppt::log::context::set(
    fcppt::log::location const &_location, fcppt::log::optional_level const &_level)
{
  impl::lock_guard const lock{this->impl_->mutex()};

  for (fcppt::log::detail::context_tree &node : fcppt::container::tree::make_pre_order(
           this->impl_->find_location_impl(_location, lock).get()))
  {
    node.value().level(_level);
  }
}

fcppt::log::optional_level fcppt::log::context::get(fcppt::log::location const &_location) const
{
  impl::lock_guard const lock{this->impl_->mutex()};

  return fcppt::algorithm::fold_break(
             _location,
             this->root(),
             [](fcppt::string const &_item,
                fcppt::reference<fcppt::log::detail::context_tree const> const _cur) {
               return fcppt::optional::maybe(
                   fcppt::log::impl::find_child_const(_cur, fcppt::log::name{_item}),
                   [_cur] { return std::make_pair(fcppt::loop::break_, _cur); },
                   [](fcppt::reference<fcppt::log::detail::context_tree const> const _result) {
                     return std::make_pair(fcppt::loop::continue_, _result);
                   });
             })
      .get()
      .value()
      .level();
}

fcppt::log::const_level_stream_array_reference fcppt::log::context::level_streams() const
{
  return this->impl_->streams();
}

fcppt::reference<fcppt::log::detail::context_tree const> fcppt::log::context::root() const
{
  return this->impl_->root();
}

fcppt::reference<fcppt::log::detail::context_tree const>
fcppt::log::context::find_location(fcppt::log::location const &_location)
{
  impl::lock_guard const lock{this->impl_->mutex()};

  return fcppt::reference_to_const(this->impl_->find_location_impl(_location, lock));
}

fcppt::reference<fcppt::log::detail::context_tree const> fcppt::log::context::find_child(
    fcppt::reference<fcppt::log::detail::context_tree const> const _node,
    fcppt::log::name const &_name)
{
  impl::lock_guard const lock{this->impl_->mutex()};

  return fcppt::reference_to_const(fcppt::log::impl::find_or_create_child(
      fcppt::make_ref(
          // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
          const_cast<fcppt::log::detail::context_tree &>(_node.get())),
      _name));
}

fcppt::log::context::impl::impl(
    fcppt::log::optional_level const &_root_level, fcppt::log::level_stream_array &&_streams)
    : mutex_{},
      tree_{fcppt::log::detail::context_tree_node(fcppt::log::name{fcppt::string()}, _root_level)},
      streams_{std::move(_streams)}
{
}

fcppt::log::context::impl::~impl() = default;

fcppt::reference<fcppt::log::detail::context_tree>
fcppt::log::context::impl::find_location_impl(fcppt::log::location const &_location, lock_guard const &)
{
  return fcppt::algorithm::fold(
      _location,
      fcppt::make_ref(this->tree_),
      [](fcppt::string const &_item,
         fcppt::reference<fcppt::log::detail::context_tree> const _cur) {
        return fcppt::log::impl::find_or_create_child(_cur, fcppt::log::name{_item});
      });
}

fcppt::log::context::impl::mutex_type &fcppt::log::context::impl::mutex()
{
  return this->mutex_;
}

fcppt::reference<fcppt::log::detail::context_tree const> fcppt::log::context::impl::root() const
{
  return fcppt::make_cref(this->tree_);
}

fcppt::log::const_level_stream_array_reference fcppt::log::context::impl::streams() const
{
  return fcppt::make_cref(this->streams_);
}
