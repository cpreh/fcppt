//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/container/field_impl.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <vector>

int main()
{
	typedef fcppt::container::field<
		fcppt::container::raw_vector<
			bool
		>
	> field_vector;

	typedef std::vector<
		field_vector
	> vector_of_fields;

	vector_of_fields outer;

	for(
		unsigned i = 0;
		i < 100;
		++i
	)
	{
		field_vector test(
			field_vector::dim(
				4,
				1
			)
		);

		outer.push_back(
			test	
		);
	}

	fcppt::io::cout
		<< outer[42]
		<< FCPPT_TEXT('\n');
}
