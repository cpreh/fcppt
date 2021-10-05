//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/signal/base_decl.hpp>
#include <fcppt/signal/object_fwd.hpp>

namespace fcppt::signal
{
/**
\brief Represents a signal with a non-void return value
\tparam Base The signal's base class (determines the existence of unregister functions)
\ingroup fcpptsignal
*/
template <typename Result, typename... Args, template <typename> class Base>
class object<Result(Args...),Base> : private Base<Result(Args...)>
{
  FCPPT_NONCOPYABLE(object);

public:
  /**
  \brief A typedef for the function's return type
  */
  using result_type = Result;

  /**
  \brief A typedef for the signal's base class
  */
  using base = Base<Result(Args...)>;

  using function = typename base::function;

  /**
  \brief Typedef to the combiner function
  */
  using combiner_function = fcppt::function<result_type(result_type, result_type)>;

  FCPPT_DECLARE_STRONG_TYPEDEF(result_type, initial_value);

  /**
  \brief Construct a signal with a combiner
  */
  explicit object(combiner_function &&);

  object(object &&) noexcept;

  object &operator=(object &&) noexcept;

  ~object();

  /**
  \brief Call the signal
  */
  Result operator()(initial_value &&, Args...);

  using base::connect;

  using base::empty;

  using base::connections;

private:
  combiner_function combiner_;
};

/**
\brief Represents a signal without a return value
\tparam Base The signal's base class (determines the existence of unregister functions)
\ingroup fcpptsignal
*/
template <typename... Args, template <typename> class Base>
class object<void(Args...), Base> : private Base<void(Args...)>
{
  FCPPT_NONCOPYABLE(object);

public:
  /**
  \brief A typedef for the signal's base class
  */
  using base = Base<void(Args...)>;

  using function = typename base::function;

  /**
  \brief Construct an empty signal
  */
  object();

  object(object &&) noexcept;

  object &operator=(object &&) noexcept;

  ~object();

  /**
  \brief Typedef to the function's return type
  */
  using result_type = void;

  /**
  \brief Call the signal
  */
  void operator()(Args ...);

  using base::connect;

  using base::empty;

  using base::connections;
};

}

#endif
