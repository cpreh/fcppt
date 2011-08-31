//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{

class base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	base()
	{
	}

	virtual int
	foo() = 0;

	virtual ~base()
	{
	}
};

class derived
:
	public base
{
	FCPPT_NONCOPYABLE(
		derived
	);
public:
	derived()
	{
	}
private:
	int
	foo()
	{
		return 42;
	}
};

void
test(
	base &_base
)
{
	BOOST_REQUIRE(
		_base.foo()
		== 42
	);
}

template<
	typename T
>
void
reffun(
	T const &_t
)
{
	test(
		_t
	);
}

}

BOOST_AUTO_TEST_CASE(
	ref
)
{
	derived der;

	reffun(
		fcppt::ref(
			der
		)
	);
}
