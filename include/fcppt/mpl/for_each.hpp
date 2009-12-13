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


#ifndef SGE_MPL_FOR_EACH_HPP_INCLUDED
#define SGE_MPL_FOR_EACH_HPP_INCLUDED

#include <sge/workarounds.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>

namespace sge
{
namespace mpl
{
namespace detail
{

template<bool done = true>
class for_each_impl {
public:
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Iterator *,
		LastIterator *,
		Fun const &)
	{}
};

template<>
class for_each_impl<false> {
public:
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Iterator *,
		LastIterator *,
		Fun const &f)
	{
		typedef typename boost::mpl::deref<Iterator>::type item;
		typedef typename boost::mpl::next<Iterator>::type iter;

#ifdef SGE_MSVC_DEPENDANT_TEMPLATE_BUG
		f.operator()<item>();
#else
		f. template operator()<item>();
#endif
		for_each_impl<
			boost::is_same<iter, LastIterator>::value
		>::execute(
			static_cast<iter *>(0),
			static_cast<LastIterator *>(0),
			f
		);
	}
};

}

template<
	typename Sequence,
	typename Fun
>
void
for_each(
	Fun const &f)
{
	typedef typename boost::mpl::begin<Sequence>::type first;
	typedef typename boost::mpl::end<Sequence>::type last;

	return detail::for_each_impl<
		boost::is_same<first, last>::value
	>::execute(
		static_cast<first *>(0),
		static_cast<last *>(0),
		f
	);
}

}
}

#endif
