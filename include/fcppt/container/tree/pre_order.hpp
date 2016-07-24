//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED

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
			typename
			std::remove_cv<
				Tree
			>::type
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
		tree_(
			_tree
		)
	{
	}

	class iterator;
private:
	typedef
	typename
	std::conditional<
		std::is_const<
			Tree
		>::value,
		typename
		Tree::const_reverse_iterator,
		typename
		Tree::reverse_iterator
	>::type
	tree_iterator;

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
	std::stack<
		tree_ref
	>
	stack_type;

	typedef
	boost::iterator_facade<
		iterator,
		typename
		tree_iterator::value_type,
		std::forward_iterator_tag,
		typename
		tree_iterator::reference
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
			),
			positions_()
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
					boost::make_iterator_range(
						cur_deref.rbegin(),
						std::prev(
							cur_deref.rend()
						)
					)
				)
					positions_.push(
						tree_ref(
							element
						)
					);

				current_ =
					optional_tree_ref(
						tree_ref(
							cur_deref.front()
						)
					);
			}
			else if(
				positions_.empty()
			)
				current_ =
					optional_tree_ref();
			else
			{

				current_ =
					optional_tree_ref(
						positions_.top()
					);

				positions_.pop();
			}
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

		stack_type positions_;
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
