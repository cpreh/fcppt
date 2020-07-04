//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::line_counting_rdbuf",
	"[parse]"
)
{
	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	std::istringstream stringstream{
		"test\n123\n"
	};

	fcppt::parse::detail::line_counting_rdbuf<
		char
	> streambuf{
		fcppt::reference_to_base<
			std::streambuf
		>(
			fcppt::make_ref(
				*stringstream.rdbuf()
			)
		)
	};

	std::istream stream{
		&streambuf
	};

	CHECK(
		streambuf.get_line()
		==
		fcppt::parse::line_number{
			1U
		}
	);

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	stream.ignore(
		4U
	);

	CHECK(
		streambuf.get_line()
		==
		fcppt::parse::line_number{
			1U
		}
	);

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	stream.ignore(
		1U
	);

	CHECK(
		streambuf.get_line()
		==
		fcppt::parse::line_number{
			2U
		}
	);

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	stream.ignore(
		3U
	);

	CHECK(
		streambuf.get_line()
		==
		fcppt::parse::line_number{
			2U
		}
	);

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	stream.ignore(
		1U
	);

	CHECK(
		streambuf.get_line()
		==
		fcppt::parse::line_number{
			3U
		}
	);
}
