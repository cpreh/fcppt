//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//[randomactor
#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/container.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

void
test1()
{
	fcppt::io::cout
		<< FCPPT_TEXT("test1\n");
}

void
test2()
{
	fcppt::io::cout
		<< FCPPT_TEXT("test2\n");
}

}

int main()
{
	// create an actor whose probability
	// to call test2 is twice as high as test1
	fcppt::random::actor::normalized actor(
		fcppt::assign::make_container<
			fcppt::random::actor::container
		>(
			fcppt::random::actor::element(
				5.f,
				test1
			)
		)
		(
			fcppt::random::actor::element(
				10.f,
				test2
			)
		)
	);

	// call the actor 10 times
	for(
		unsigned i = 0;
		i < 10;
		++i
	)
		actor();
}
//]
