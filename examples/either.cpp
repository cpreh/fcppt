//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/apply.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [either_read_raw]
typedef
std::pair<
	int,
	std::string
>
int_string_pair;

int_string_pair
read_stream_raw(
	std::istream &_stream
)
{
	int result_int;

	if(
		!(_stream >> result_int)
	)
		throw
			std::runtime_error{
				"Failed reading the int"
			};

	std::string result_string;

	if(
		!(_stream >> result_string)
	)
		throw
			std::runtime_error{
				"Failed reading the string"
			};

	return
		int_string_pair{
			result_int,
			result_string
		};
}
//! [either_read_raw]

//! [either_read]
template<
	typename Type
>
fcppt::either::object<
	std::runtime_error,
	Type
>
read(
	std::istream &_stream,
	std::string const &_error
)
{
	Type result;

	typedef
	fcppt::either::object<
		std::runtime_error,
		Type
	>
	result_type;

	return
		_stream >> result
		?
			result_type{
				result
			}
		:
			result_type{
				std::runtime_error{
					_error
				}
			}
		;
}
//! [either_read]

//! [either_read_apply]
fcppt::either::object<
	std::runtime_error,
	int_string_pair
>
read_stream_either(
	std::istream &_stream
)
{
	fcppt::either::object<
		std::runtime_error,
		int
	> const either_int(
		read<
			int
		>(
			_stream,
			"read int"
		)
	);

	fcppt::either::object<
		std::runtime_error,
		std::string
	> const either_string(
		read<
			std::string
		>(
			_stream,
			"read string"
		)
	);

	return
		fcppt::either::apply(
			[](
				int const _i,
				std::string const &_s
			)
			{
				return
					int_string_pair(
						_i,
						_s
					);
			},
			either_int,
			either_string
		);
}
//! [either_read_apply]

//! [either_read_bind]
fcppt::either::object<
	std::runtime_error,
	int_string_pair
>
read_stream_either_bind(
	std::istream &_stream
)
{
	return
		fcppt::either::bind(
			read<
				int
			>(
				_stream,
				"read int"
			),
			[
				&_stream
			](
				int const _int_value
			)
			{
				return
					fcppt::either::map(
						read<
							std::string
						>(
							_stream,
							"read string"
						),
						[
							_int_value
						](
							std::string const &_string_value
						)
						{
							return
								std::make_pair(
									_int_value,
									_string_value
								);
						}
					);
			}
		);
}
//! [either_read_bind]

//! [either_match]
void
either_match(
	std::istream &_stream
)
{
	fcppt::either::match(
		read_stream_either(
			_stream
		),
		[](
			std::runtime_error const &_error
		)
		{
			std::cerr
				<< "Reading failed "
				<< _error.what()
				<< '\n';
		},
		[](
			int_string_pair const &_result
		)
		{
			std::cout
				<< "The result is "
				<< _result.first
				<< ", "
				<< _result.second
				<< '\n';
		}
	);
}
//! [either_match]

//! [either_to_exception]
void
either_to_exception(
	std::istream &_stream
)
{
	int_string_pair const result(
		fcppt::either::to_exception(
			read_stream_either(
				_stream
			),
			[](
				std::runtime_error const &_error
			)
			{
				return
					_error;
			}
		)
	);

	std::cout
		<< "The result is "
		<< result.first
		<< ", "
		<< result.second
		<< '\n';
}
//! [either_to_exception]

}

int
main()
{
	{
		std::istringstream stream(
			"42 test"
		);

		std::cout
			<<
			read_stream_raw(
				stream
			).first
			<<
			'\n';
	}

	{
		std::istringstream stream(
			"42 test"
		);

		std::cout
			<<
			read_stream_either(
				stream
			).has_success()
			<<
			'\n';
	}

	{
		std::istringstream stream(
			"42 test"
		);

		std::cout
			<<
			read_stream_either_bind(
				stream
			).has_success()
			<<
			'\n';
	}

	{
		std::istringstream stream(
			"42 test"
		);

		either_match(
			stream
		);
	}

	{
		std::istringstream stream(
			"42 test"
		);

		either_to_exception(
			stream
		);
	}
}
