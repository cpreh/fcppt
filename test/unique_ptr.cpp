//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	unique_ptr_int
)
{
	typedef fcppt::unique_ptr<
		int
	> int_ptr;

	int_ptr test1(
		new int(42)
	);

	int_ptr test2(
		fcppt::make_unique_ptr<
			int
		>(43)
	);

	BOOST_REQUIRE(
		*test1 == 42
	);

	BOOST_REQUIRE(
		*test2 == 43
	);

	test1 = fcppt::move(test2);

	BOOST_REQUIRE(
		!test2
	);

	BOOST_REQUIRE(
		*test1 == 43
	);
}

namespace
{

typedef fcppt::unique_ptr<
	std::string
> string_unique_ptr;

class noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	explicit noncopyable(
		string_unique_ptr
	);

	~noncopyable();

	std::string const &
	value() const;
private:
	string_unique_ptr value_;
};

noncopyable::noncopyable(
	string_unique_ptr _ptr
)
:
	value_(
		fcppt::move(
			_ptr
		)
	)
{
}

noncopyable::~noncopyable()
{
}

std::string const &
noncopyable::value() const
{
	return *value_;
}

typedef fcppt::unique_ptr<
	noncopyable
> noncopyable_unique_ptr;

noncopyable_unique_ptr
noncopyable_factory()
{
	return
		fcppt::make_unique_ptr<
			noncopyable
		>(
			fcppt::make_unique_ptr<
				std::string
			>(
				"foo"
			)
		);
}

}

BOOST_AUTO_TEST_CASE(
	unique_ptr_nested
)
{
	noncopyable_unique_ptr ptr(
		noncopyable_factory()
	);

	BOOST_REQUIRE(
		ptr->value() == "foo"
	);
}
