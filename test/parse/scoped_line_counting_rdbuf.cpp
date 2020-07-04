//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/parse/detail/scoped_line_counting_rdbuf_impl.hpp>
#include <fcppt/parse/detail/to_line_counting_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ios>
#include <sstream>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::detail::scoped_line_counting_rdbuf",
	"[parse]"
)
{
	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	std::istringstream stream{};

	std::streambuf *const old_buffer{
		stream.rdbuf()
	};

	{
		fcppt::parse::detail::scoped_line_counting_rdbuf<
			char
		> const scoped_buffer{
			fcppt::reference_to_base<
				std::ios
			>(
				fcppt::make_ref(
					stream
				)
			)
		};

		CHECK(
			fcppt::parse::detail::to_line_counting_rdbuf(
				stream
			).has_value()
		);
	}

	CHECK(
		stream.rdbuf()
		==
		old_buffer
	);
}
