//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/detail/make_name_set_base.hpp>


fcppt::options::name_set
fcppt::options::detail::make_name_set_base(
	fcppt::options::long_name const &_long_name,
	fcppt::options::optional_short_name const &_optional_short_name
)
{
	fcppt::options::name_set result{
		_long_name.get()
	};

	// TODO: Make a function for this?
	fcppt::optional::maybe_void(
		_optional_short_name,
		[
			&result
		](
			fcppt::options::short_name const &_short_name
		)
		{
			result.insert(
				_short_name.get()
			);
		}
	);

	return
		result;
}
