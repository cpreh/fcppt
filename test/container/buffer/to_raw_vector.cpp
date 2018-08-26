//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/to_raw_vector.hpp>
#include <fcppt/container/raw_vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::buffer::to_raw_vector",
	"[container],[buffer]"
)
{
	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	buffer_type buffer{
		2u
	};

	buffer.write_data()[
		0
	]
		= 10;

	buffer.written(
		1u
	);

	typedef
	fcppt::container::raw_vector::object<
		int
	>
	raw_vector_type;

	raw_vector_type raw_vector{
		fcppt::container::buffer::to_raw_vector(
			std::move(
				buffer
			)
		)
	};

	CHECK(
		buffer.read_size()
		==
		0u
	);

	CHECK(
		buffer.write_size()
		==
		0u
	);

	CHECK(
		raw_vector.capacity()
		==
		2u
	);

	CHECK(
		raw_vector
		==
		raw_vector_type{
			10
		}
	);
}
