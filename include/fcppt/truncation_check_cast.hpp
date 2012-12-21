//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/bad_truncation_check_cast.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/type_info.hpp>
#include <fcppt/detail/truncation_check_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Cast between integral types, checking for truncation

\ingroup fcpptcasts

Casts \a _source of type \a Source to the type \a Dest. It returns the
converted value ff the conversion results in no truncation, otherwise
fcppt::bad_truncation_check_cast is thrown.

\tparam Dest Must be an integral type

\tparam Source Must be an integral type

\param _source The source to cast from

\return The casted value if no truncation occurs

\throw fcppt::bad_truncation_check_cast if truncation occurs

\see fcpptcasts_truncation_check_cast
*/
template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_integral<
			Source
		>,
		std::is_integral<
			Dest
		>
	>,
	Dest
>::type
truncation_check_cast(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	dest_type const dest(
		fcppt::detail::truncation_check_cast<
			Dest
		>(
			_source
		)
	);

	if(
		!dest
	)
		throw fcppt::bad_truncation_check_cast(
			fcppt::insert_to_fcppt_string(
				_source
			),
			fcppt::type_info(
				typeid(
					Source
				)
			),
			fcppt::type_info(
				typeid(
					Dest
				)
			)
		);

	return *dest;
}

}

#endif
