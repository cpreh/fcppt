//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_TO_ROOT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_TO_ROOT_HPP_INCLUDED

#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
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
	fcppt::optional::reference<
		Tree
	>
	optional_tree_ref;

	typedef
	fcppt::iterator::base<
		fcppt::iterator::types<
			iterator,
			tree_value_type,
			Tree &,
			typename
			tree_value_type::difference_type,
			std::forward_iterator_tag
		>
	>
	iterator_base;
public:
	class iterator final
	:
		public iterator_base
	{
	public:
		iterator()
		:
			current_{}
		{
		}

		explicit
		iterator(
			optional_tree_ref const _current
		)
		:
			current_{
				_current
			}
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
	private:
		optional_tree_ref current_;
	};

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
