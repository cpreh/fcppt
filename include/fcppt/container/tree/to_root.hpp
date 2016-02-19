//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_TO_ROOT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_TO_ROOT_HPP_INCLUDED

#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/container/tree/optional_ref_impl.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename Tree
>
class to_root
{
	typedef
	typename
	std::remove_cv<
		Tree
	>::type
	tree_value_type;

	static_assert(
		fcppt::container::tree::is_object<
			tree_value_type
		>::value,
		"to_root can only be used with trees"
	);
public:
	/**
	\brief Construct a to-root traversal from a tree (which can be const or nonconst)
	*/
	explicit
	to_root(
		Tree &_tree
	)
	:
		tree_(
			_tree
		)
	{
	}

	class iterator;
private:
	typedef
	fcppt::reference<
		Tree
	>
	tree_ref;

	typedef
	fcppt::container::tree::optional_ref<
		Tree
	>
	optional_tree_ref;

	typedef
	boost::iterator_facade<
		iterator,
		tree_value_type,
		std::forward_iterator_tag,
		Tree &
	>
	iterator_base;
public:

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

	class iterator final
	:
		public iterator_base
	{
	public:
		explicit
		iterator(
			optional_tree_ref const _current
		)
		:
			current_(
				_current
			)
		{
		}

		typedef
		typename
		iterator_base::value_type
		value_type;

		typedef
		typename
		iterator_base::reference
		reference;

		typedef
		typename
		iterator_base::pointer
		pointer;

		typedef
		typename
		iterator_base::difference_type
		difference_type;

		typedef
		typename
		iterator_base::iterator_category
		iterator_category;

		friend class boost::iterator_core_access;
	private:
		void
		increment()
		{
			current_ =
				this->dereference().parent();
		}

		reference
		dereference() const
		{
			return
				current_.get_unsafe().get();
		}

		bool
		equal(
			iterator const &_other
		) const
		{
			return
				current_
				==
				_other.current_;
		}

		optional_tree_ref current_;
	};

FCPPT_PP_POP_WARNING

	typedef
	iterator
	const_iterator;

	/**
	\brief Return an iterator to the first tree in the traversal
	*/
	iterator
	begin() const
	{
		return
			iterator(
				optional_tree_ref(
					tree_
				)
			);
	}

	/**
	\brief Return a dummy iterator to stop the traversal
	*/
	iterator
	end() const
	{
		return
			iterator(
				optional_tree_ref()
			);
	}
private:
	tree_ref tree_;
};

}
}
}

#endif
