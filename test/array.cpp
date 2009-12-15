#include <fcppt/assign/make_array.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/foreach.hpp>

int main()
{
	std::tr1::array<int,3> const a =
		fcppt::assign::make_array<int>(3)(4)(5);

	BOOST_FOREACH(int x,a)
	{
		fcppt::io::cout << x << FCPPT_TEXT('\n');
	}
}
