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


#ifndef FCPPT_MPL_DETAIL_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_INVOKE_ON_HPP_INCLUDED

#include <fcppt/mpl/invalid_invoke.hpp>
#include <fcppt/workarounds.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>

namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename Counter,
	bool Done
>
struct invoke_on;

template<
	typename Counter
>
struct invoke_on<
	Counter,
	true
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Index,
		typename Operation
	>
	static typename Operation::result_type
	execute(
		Index const &,
		Operation const &
	)
	{
		throw invalid_invoke();
	}
};

template<
	typename Counter
>
struct invoke_on<
	Counter,
	false
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Index,
		typename Operation
	>
	static typename Operation::result_type
	execute(
		Index const &index,
		Operation const &op
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type item;

		typedef typename boost::mpl::next<
			Iterator
		>::type iter;

		return Counter::value == index
			?
#ifdef FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
			op.operator()<
				item
			>()
#else

			op. template operator()<
				item
			>()
#endif
			: detail::invoke_on<
				typename boost::mpl::next<
					Counter
				>::type,
				boost::is_same<
					iter,
					LastIterator
				>::value
			>:: template execute<
				iter,
				LastIterator
			>(
				index,
				op
			);
	}
};

}
}
}

#endif
