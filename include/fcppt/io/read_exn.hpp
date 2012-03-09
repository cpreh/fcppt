//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_EXN_HPP_INCLUDED
#define FCPPT_IO_READ_EXN_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

template<
	typename Type
>
typename boost::enable_if<
	boost::is_fundamental<
		Type
	>,
	Type
>::type
read_exn(
	std::istream &_stream,
	fcppt::endianness::format::type const _format
)
{
	typedef fcppt::optional<
		Type
	> result_type;

	result_type const result(
		fcppt::io::read<
			Type
		>(
			_stream,
			_format
		)
	);

	if(
		!result
	)
		throw fcppt::exception(
			FCPPT_TEXT("read_exn failed!")
		);

	return
		*result;
}

}
}

#endif
