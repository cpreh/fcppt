//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <ostream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		std::string const &_value
	)
	:
		value_(
			_value
		)
	{
	}

	movable(
		movable &&
	) = default;

	movable &
	operator=(
		movable &&
	) = default;

	~movable()
	{
	}

	std::string const &
	value() const
	{
		return
			value_;
	}
private:
	std::string value_;
};

bool
operator==(
	movable const &_left,
	movable const &_right
)
{
	return
		_left.value()
		==
		_right.value();
}

std::ostream &
operator<<(
	std::ostream &_stream,
	movable const &_object
)
{
	return
		_stream
		<<
		_object.value();
}

}

TEST_CASE(
	"optional move",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		movable
	>
	optional_movable;

	optional_movable opta(
		movable(
			"test"
		)
	);

	optional_movable optb(
		std::move(
			opta
		)
	);

	CHECK(
		!opta.has_value()
	);

	CHECK(
		optb
		==
		optional_movable{
			movable{
				"test"
			}
		}
	);

	optional_movable optc(
		movable(
			"test2"
		)
	);

	optc =
		std::move(
			optb
		);

	CHECK(
		!optb.has_value()
	);

	CHECK(
		optc
		==
		optional_movable{
			movable{
				"test"
			}
		}
	);

	optional_movable optd{};

	optd =
		optional_movable(
			movable(
				"test3"
			)
		);

	CHECK(
		optd
		==
		optional_movable{
			movable{
				"test3"
			}
		}
	);

	optd =
		optional_movable(
			movable(
				"test4"
			)
		);

	CHECK(
		optd
		==
		optional_movable{
			movable{
				"test4"
			}
		}
	);
}
