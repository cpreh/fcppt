//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::map",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		std::string::size_type
	>
	optional_size;

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	auto const conversion(
		[](
			std::string const &_val
		)
		{
			return
				_val.size();
		}
	);

	CHECK(
		fcppt::optional::map(
			optional_string(),
			conversion
		)
		==
		optional_size()
	);

	CHECK(
		fcppt::optional::map(
			optional_string(
				"test"
			),
			conversion
		)
		==
		optional_size(
			4u
		)
	);
}

namespace
{

class noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	noncopyable()
	{
	}

	~noncopyable()
	{
	}
};

}

TEST_CASE(
	"optional::map ref",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	noncopyable test{};

	typedef
	fcppt::optional::reference<
		noncopyable
	>
	optional_noncopyable_ref;

	CHECK(
		fcppt::optional::map(
			optional_string(
				"42"
			),
			[
				&test
			](
				std::string
			)
			{
				return
					fcppt::make_ref(
						test
					);
			}
		)
		==
		optional_noncopyable_ref{
			fcppt::make_ref(
				test
			)
		}
	);
}
