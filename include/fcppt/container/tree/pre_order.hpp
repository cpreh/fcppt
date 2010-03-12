//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED

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
class pre_order
{
	BOOST_STATIC_ASSERT(
		is_object<
			typename boost::remove_const<
				Tree
			>::type
		>::value
	);

	FCPPT_NONCOPYABLE(pre_order)
public:
	explicit pre_order(
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
		Tree *
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
		explicit iterator(
			Tree *const current
		)
		:
			current(current),
			positions()
		{}

		typedef typename iterator_base::value_type value_type;
		typedef typename iterator_base::reference reference;
		typedef typename iterator_base::pointer pointer;
		typedef typename iterator_base::difference_type difference_type;
		typedef typename iterator_base::iterator_category iterator_category;

		friend class boost::iterator_core_access;
	private:
		void
		increment()
		{
			if(!current->empty())
			{
				for(
					tree_iterator it(
						boost::next(
							current->begin()
						)
					);
					it != current->end();
					++it
				)
					positions.push(
						&*it
					);

				current = &current->front();
			}
			else if(
				positions.empty()
			)
				current = 0;
			else
			{

				current = positions.top();

				positions.pop();
			}
		}

		reference
		dereference() const
		{
			return *current;
		}

		bool
		equal(
			iterator const &s
		) const
		{
			return current == s.current;
		}

		Tree *current;

		stack_type positions;
	};

	iterator const
	begin() const
	{
		return iterator(
			&tree_
		);
	}
	iterator const
	end() const
	{
		return iterator(
			0
		);
	}
private:
	Tree &tree_;
};

}
}
}

#endif
