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


#ifndef FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED

#include <fcppt/workarounds.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename Done
>
struct for_each;

template<>
struct for_each<
	boost::true_type
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Fun const &
	)
	{}
};

template<>
struct for_each<
	boost::false_type
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Fun const &f
	)
	{
		typedef typename boost::mpl::deref<Iterator>::type item;
		typedef typename boost::mpl::next<Iterator>::type iter;

#ifdef FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
		f.operator()<item>();
#else
		f. template operator()<item>();
#endif
		detail::for_each<
			typename boost::is_same<
				iter,
				LastIterator
			>::type
		>:: template execute<
			iter,
			LastIterator
		>(
			f
		);
	}
};

}
}
}

#endif
