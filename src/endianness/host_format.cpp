//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/format.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config.hpp>

#if defined(FCPPT_LITTLE_ENDIAN) && defined(FCPPT_BIG_ENDIAN)
#error "FCPPT_LITTLE_ENDIAN and FCPPT_BIG_ENDIAN defined!"
#endif

#if !(defined(FCPPT_LITTLE_ENDIAN) || defined(FCPPT_BIG_ENDIAN))
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace
{

fcppt::endianness::format
compute_endianness()
{
	typedef unsigned long int_type;

	int_type const int_value(
		1u
	);

	typedef std::array<
		unsigned char,
		sizeof(int_type)
	> array_type;

	array_type array;

	fcppt::algorithm::copy_n(
		reinterpret_cast<
			unsigned char const *
		>(
			&int_value
		),
		sizeof(int_type),
		array.data()
	);

	return
		array[0] == int_value
		?
			fcppt::endianness::format::little
		:
			fcppt::endianness::format::big;
}

struct init
{
	FCPPT_NONCOPYABLE(
		init
	);
public:
	init();

	~init();

	fcppt::endianness::format const endianness_;
} instance;

init::init()
:
	endianness_(
		compute_endianness()
	)
{
}

}

init::~init()
{
}
#endif

fcppt::endianness::format
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
