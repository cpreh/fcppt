//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/options/impl/next_arg.hpp>


fcppt::optional::object<
	fcppt::args_vector::const_iterator
>
fcppt::options::impl::next_arg(
	fcppt::args_vector const &_args,
	fcppt::options::option_name_set const &_option_names
)
{
	typedef
	fcppt::optional::object<
		fcppt::args_vector::const_iterator
	>
	result_type;

	fcppt::args_vector::const_iterator const end{
		_args.end()
	};

	// TODO: This is terrible
	for(
		fcppt::args_vector::const_iterator cur{
			_args.begin()
		};
		cur != end;
	)
	{
		if(
			fcppt::options::impl::is_flag(
				*cur
			)
		)
		{
			++cur;

			if(
				cur
				!=
				end
				&&
				_option_names.get().count(
					*cur
				)
				>=
				1u
			)
				++cur;

			continue;
		}

		return
			result_type{
				cur
			};
	}

	return
		result_type{};
}
