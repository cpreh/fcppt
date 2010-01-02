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


#ifndef FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/variant/invalid_apply.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/at.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Counter,
	typename Done
>
struct apply;

template<
	typename Counter
>
struct apply<
	Counter,
	boost::true_type
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &,
		Variant const &
	)
	{
		throw invalid_apply();
	}
};

template<
	typename Counter
>
struct apply<
	Counter,
	boost::false_type
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &op,
		Variant const &obj
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type item;

		typedef typename boost::mpl::next<
			Iterator
		>::type iter;

		typedef typename boost::mpl::at<
			typename Variant::types,
			Counter
		>::type type;

		return Counter::value == obj.type_index()
			? op(
				obj. template get<type>()
			)
			: detail::apply<
				typename boost::mpl::next<
					Counter
				>::type,
				typename boost::is_same<
					iter,
					LastIterator
				>::type
			>:: template execute<
				iter,
				LastIterator
			>(
				op,
				obj
			);
	}
};

}
}
}

#endif
