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


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/raw_type.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/mpl/max_value.hpp>
#include <fcppt/alignment/array.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <typeinfo>

namespace fcppt
{
namespace variant
{

template<
	typename Types
>
class object
{
public:
	typedef Types types;

	object();

	// intentionally not explicit
	template<
		typename U
	>
	object(
		U const &
	);

	object(
		object const &
	);

	template<
		typename U
	>
	object &
	operator=(
		U const &
	);

	object &
	operator=(
		object const &
	);

	~object();

	bool
	empty() const;

	template<
		typename U
	>
	U const &
	get() const;

	template<
		typename U
	>
	U &
	get();

	std::type_info const &
	type() const;

	size_type
	type_index() const;
private:
	template<
		typename U
	>
	void
	check_get() const;

	template<
		typename U
	>
	void
	construct(
		U const &
	);

	void
	destroy();

	static size_type const elements =
		boost::mpl::size<
			Types
		>::value
	;

	typedef typename alignment::array<
		raw_type,
		mpl::max_value<
			Types,
			boost::mpl::sizeof_<
				boost::mpl::_1
			>
		>::value,
		mpl::max_value<
			Types,
			boost::alignment_of<
				boost::mpl::_1
			>
		>::value
	>::type storage_type;

	storage_type storage_;
	size_type index_;
	void *data_;
};

}
}

#endif
