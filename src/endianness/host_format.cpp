//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/host_format.hpp>
#include <fcppt/config.hpp>

#if defined(FCPPT_LITTLE_ENDIAN) && defined(FCPPT_BIG_ENDIAN)
#error "FCPPT_LITTLE_ENDIAN and FCPPT_BIG_ENDIAN defined!"
#endif

#if !(defined(FCPPT_LITTLE_ENDIAN) || defined(FCPPT_BIG_ENDIAN))
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/function_once.hpp>

namespace
{

fcppt::endianness::format::type endianness_;

void
init()
{
	FCPPT_FUNCTION_ONCE	

	// if unsigned long and char are of the same size
	// endianness doesn't matter

	typedef unsigned long int_type;

	int_type const t = 1u;

	typedef std::tr1::array<
		unsigned char,
		sizeof(int_type)
	> array_type;

	array_type array;

	fcppt::algorithm::copy_n(
		reinterpret_cast<
			unsigned char const *
		>(
			&t
		),
		sizeof(int_type),
		array.data()
	);

	endianness_ =
		array[0] == t
		?
			fcppt::endianness::format::little
		:
			fcppt::endianness::format::big;
}

}
#endif

fcppt::endianness::format::type
fcppt::endianness::host_format()
{
#if   defined(FCPPT_LITTLE_ENDIAN)
	return format::little;
#elif defined(FCPPT_BIG_ENDIAN)
	return format::big;
#else
	init();

	return endianness_;
#endif
}
