//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_IN_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_IN_ORDER_HPP_INCLUDED

#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/next_prior.hpp>
#include <boost/static_assert.hpp>
#include <stack>

namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename Tree
>
class in_order
{
	BOOST_STATIC_ASSERT(
		is_object<
			typename boost::remove_const<
				Tree
			>::type
		>::value
	);

	FCPPT_NONCOPYABLE(in_order)
public:
	explicit in_order(
		Tree &tree_
	)
	:
		tree_(tree_)
	{}

	class iterator;
private:
	typedef typename boost::mpl::if_<
		boost::is_const<
			Tree
		>,
		typename Tree::const_iterator,
		typename Tree::iterator
	>::type tree_iterator;

	typedef std::stack<
		tree_iterator
	> stack_type;

	typedef typename Tree::child_list child_list;

	typedef boost::iterator_facade<
		iterator,
		typename tree_iterator::value_type,
		boost::forward_traversal_tag,
		typename tree_iterator::reference
	> iterator_base;
public:
	class iterator
	:
		public iterator_base
	{
	public:
		iterator(
			tree_iterator const &it,
			Tree *const current
		)
		:
			it(it),
			current(current),
			positions()
		{}

		typedef typename iterator_base::value_type value_type;
		typedef typename iterator_base::reference reference;
		typedef typename iterator_base::pointer pointer;
		typedef typename iterator_base::difference_type difference_type;
		typedef typename iterator_base::iterator_category iterator_category;

		tree_iterator const
		internal() const
		{
			return it;
		}

		friend class boost::iterator_core_access;
	private:
		void
		increment()
		{
			if(!it->empty())
			{
				positions.push(it);
				current = &*it;
				it = it->begin();
			}
			else
			{
				while(
					!positions.empty()
					&& boost::next(
						positions.top()
					)
					== positions.top()->parent().end()
				)
				{
					it = positions.top();
					current = it->parent_ptr();
					positions.pop();
				}
				++it;
			}
		}

		reference
		dereference() const
		{
			return *it;
		}

		bool
		equal(
			iterator const &s
		) const
		{
			return
				current == s.current
				&& it == s.it;
		}

		tree_iterator it;
		Tree *current;
		stack_type positions;
	};

	iterator const
	begin() const
	{
		return iterator(
			tree_.begin(),
			&tree_
		);
	}
	iterator const
	end() const
	{
		return iterator(
			tree_.end(),
			&tree_
		);
	}
private:
	Tree &tree_;
};

}
}
}

#endif
