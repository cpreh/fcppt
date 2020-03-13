//          Copyright Carl Philipp Reh 2009 - 2020.
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
#include <fcppt/type_traits/value_type.hpp>
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
	using
	tree_value_type
	=
	std::remove_cv_t<
		Tree
	>;

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
	using
	tree_ref
	=
	fcppt::reference<
		Tree
	>;

	using
	optional_tree_ref
	=
	fcppt::optional::reference<
		Tree
	>;

	using
	iterator_base
	=
	fcppt::iterator::base<
		fcppt::iterator::types<
			iterator,
			tree_value_type,
			Tree &,
			typename
			tree_value_type::difference_type,
			std::forward_iterator_tag
		>
	>;
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

		using
		value_type
		=
		fcppt::type_traits::value_type<
			iterator_base
		>;

		using
		reference
		=
		typename
		iterator_base::reference;

		using
		pointer
		=
		typename
		iterator_base::pointer;

		using
		difference_type
		=
		typename
		iterator_base::difference_type;

		using
		iterator_category
		=
		typename
		iterator_base::iterator_category;

		void
		increment()
		{
			current_ =
				this->dereference().parent();
		}

		[[nodiscard]]
		reference
		dereference() const
		{
			return
				current_.get_unsafe().get();
		}

		[[nodiscard]]
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

	using
	const_iterator
	=
	iterator;

	/**
	\brief Return an iterator to the first tree in the traversal
	*/
	[[nodiscard]]
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
	[[nodiscard]]
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
