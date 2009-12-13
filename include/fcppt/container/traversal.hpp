/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_TRAVERSAL_HPP_INCLUDED
#define SGE_CONTAINER_TRAVERSAL_HPP_INCLUDED

#include <sge/assert.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/next_prior.hpp>
#include <stack>

namespace sge
{
namespace container
{

template<
	typename Tree
>
class traversal {
public:
	explicit traversal(
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

#endif
