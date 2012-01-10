//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/bad_truncation_check_cast.hpp>
#include <fcppt/type_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/utility/enable_if.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/// Does a static_cast but tries to detect narrowing conversions
/**
 * @throws If the new value cannot be cast back safely, fcppt::bad_truncation_check_cast will be thrown
*/
template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			Source
		>,
		boost::is_fundamental<
			Dest
		>
	>,
	Dest
>::type
truncation_check_cast(
	Source const source
)
{
	Dest const dest(
		static_cast<
			Dest
		>(
			source
		)
	);

	if(
		static_cast<
			Source
		>(
			dest
		)
		!= source
	)
		throw bad_truncation_check_cast(
			fcppt::type_info(
				typeid(Source)
			),
			fcppt::type_info(
				typeid(Dest)
			)
		);

	return dest;
}

}

#endif
