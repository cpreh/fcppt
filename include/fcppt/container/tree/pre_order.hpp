//          Copyright Carl Philipp Reh 2009 - 2011.
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
		Tree &_tree
	)
	:
		tree_(_tree)
	{}

	class iterator;
private:
	typedef typename boost::mpl::if_<
		boost::is_const<
			Tree
		>,
		typename Tree::const_reverse_iterator,
		typename Tree::reverse_iterator
	>::type tree_iterator;

	typedef typename tree_iterator::pointer tree_pointer; 

	typedef std::stack<
		tree_pointer	
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
			tree_pointer const _current
		)
		:
			current_(_current),
			positions_()
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
			if(!current_->empty())
			{
				for(
					tree_iterator
						it(
							current_->rbegin()
						),
						end(
							boost::prior(
								current_->rend()
							)
						);
					it != end;
					++it
				)
					positions_.push(
						&*it
					);

				current_ = &current_->front();
			}
			else if(
				positions_.empty()
			)
				current_ = 0;
			else
			{

				current_ = positions_.top();

				positions_.pop();
			}
		}

		reference
		dereference() const
		{
			return *current_;
		}

		bool
		equal(
			iterator const &_other
		) const
		{
			return current_ == _other.current_;
		}

		tree_pointer current_;

		stack_type positions_;
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
