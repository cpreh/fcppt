//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::buffer::read_from",
	"[container],[buffer]"
)
{
	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	buffer_type const result{
		fcppt::container::buffer::read_from<
			buffer_type
		>(
			10u,
			[](
				buffer_type::pointer const _data,
				buffer_type::size_type
			)
			{
				_data[
					0
				] = 10;

				_data[
					1
				] = 20;

				return
					2u;
			}
		)
	};

	CHECK(
		result.write_size()
		==
		8u
	);

	REQUIRE(
		result.read_size()
		==
		2u
	);

	CHECK(
		result[0]
		==
		10
	);

	CHECK(
		result[1]
		==
		20
	);
}
