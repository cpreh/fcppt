//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/dynamic_any.hpp>
#include <fcppt/cast/dynamic_any_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	FCPPT_NONCOPYABLE(
		base
	);

	base()
	{
	}

	virtual
	~base()
	{
	}
};

struct derived1
:
	base
{
	FCPPT_NONCOPYABLE(
		derived1
	);

	derived1()
	{
	}

	~derived1()
	override
	{
	}
};

struct other
{
	FCPPT_NONCOPYABLE(
		other
	);

	other()
	{
	}

	virtual
	~other()
	{
	}
};

}

TEST_CASE(
	"cast::dynamic_any",
	"[cast]"
)
{
	derived1 d1{};

	other d2{};

	base &b1{
		d1
	};

	CHECK(
		fcppt::cast::dynamic_any<
			derived1
		>(
			b1
		).has_value()
	);

	CHECK(
		fcppt::cast::apply<
			fcppt::cast::dynamic_any_fun,
			derived1
		>(
			b1
		).has_value()
	);

	CHECK_FALSE(
		fcppt::cast::dynamic_any<
			other
		>(
			b1
		).has_value()
	);
}
