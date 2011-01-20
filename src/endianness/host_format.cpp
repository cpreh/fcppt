//          Copyright Carl Philipp Reh 2009 - 2011.
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
#include <fcppt/container/array.hpp>

namespace
{

struct init
{
	init();

	fcppt::endianness::format::type endianness_;

} instance;

init::init()
{
	// if unsigned long and char are of the same size
	// endianness doesn't matter

	typedef unsigned long int_type;

	int_type const t = 1u;

	typedef fcppt::container::array<
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
	return instance.endianness_;
#endif
}
