//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/parse/repetition_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::parse::repetition_result<
				char
			>,
			std::string
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::repetition_result<
				wchar_t
			>,
			std::wstring
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::repetition_result<
				int
			>,
			std::vector<
				int
			>
		>,
		""
	);
}
