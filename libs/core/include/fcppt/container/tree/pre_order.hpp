//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED

#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <stack>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Wraps a tree to make it iterable in a pre-order fashion.

\ingroup fcpptcontainertree

Internally, this class manages a stack, losely imitating the runtime stack in a
recursive implementation.

<strong>Example:</strong>

\snippet container/tree_traversal.cpp main
*/
template<
	typename Tree
>
class pre_order
{
	static_assert(
		fcppt::container::tree::is_object<
			std::remove_cv_t<
				Tree
			>
		>::value,
		"pre_order can only be used with trees"
	);
public:
	/**
	\brief Construct a pre-order traversal from a tree (which can be const or nonconst)
	*/
	explicit
	pre_order(
		Tree &_tree
	)
	:
		tree_{
			_tree
		}
	{
	}

	class iterator;
private:
	using
	tree_iterator
	=
	std::conditional_t<
		std::is_const_v<
			Tree
		>,
		typename
		Tree::const_reverse_iterator,
		typename
		Tree::reverse_iterator
	>;

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
	stack_type
	=
	std::stack<
		tree_ref
	>;

	using
	iterator_base
	=
	fcppt::iterator::base<
		fcppt::iterator::types<
			iterator,
			fcppt::type_traits::value_type<
				tree_iterator
			>,
			typename
			tree_iterator::reference,
			typename
			tree_iterator::difference_type,
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
			current_{},
			positions_{}
		{
		}

		explicit
		iterator(
			optional_tree_ref const _current
		)
		:
			current_(
				_current
			),
			positions_()
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
			reference cur_deref(
				this->dereference()
			);

			if(
				!cur_deref.empty()
			)
			{
				for(
					reference element
					:
					fcppt::iterator::make_range(
						cur_deref.rbegin(),
						// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
						std::prev(
							cur_deref.rend()
						)
					)
				)
				{
					this->positions_.push(
						tree_ref(
							element
						)
					);
				}

				this->current_ =
					cur_deref.front();
			}
			else if(
				this->positions_.empty()
			)
			{
				this->current_ =
					optional_tree_ref();
			}
			else
			{

				this->current_ =
					optional_tree_ref(
						this->positions_.top()
					);

				this->positions_.pop();
			}
		}

		[[nodiscard]]
		reference
		dereference() const
		{
			return
				this->current_.get_unsafe().get();
		}

		[[nodiscard]]
		bool
		equal(
			iterator const &_other
		) const
		{
			return
				this->current_
				==
				_other.current_;
		}
	private:
		optional_tree_ref current_;

		stack_type positions_;
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
					this->tree_
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
