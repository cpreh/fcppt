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
#include <boost/type_traits/is_integral.hpp>
#include <boost/utility/enable_if.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_integral<
			Source
		>,
		boost::is_integral<
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
