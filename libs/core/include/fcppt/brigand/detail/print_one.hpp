//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_PRINT_ONE_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_PRINT_ONE_HPP_INCLUDED

#include <fcppt/type_name.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename Type
>
inline
void
print_one(
	fcppt::io::ostream &_stream
)
{
	_stream
		<<
		fcppt::type_name(
			typeid(
				Type
			).name()
		);
}

}
}
}

#endif
