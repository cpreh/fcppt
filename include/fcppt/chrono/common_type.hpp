//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_COMMON_TYPE_HPP_INCLUDED
#define FCPPT_CHRONO_COMMON_TYPE_HPP_INCLUDED

#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/ratio.hpp>
#define BOOST_TYPEOF_SILENT
#include <boost/typeof/typeof.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename T,
	typename U
>
struct common_type {
//private: silence gcc warning about everything being private
	static T m_t();
	static U m_u();
public:
	typedef BOOST_TYPEOF_TPL(true ? m_t() : m_u()) type;
};

template<
	typename T
>
struct common_type<
	T,
	void
>
{
	typedef T type;
};

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
struct common_type<
	chrono::duration<
		Rep1,
		Period1
	>,
	chrono::duration<
		Rep2,
		Period2
	>
>
{
	typedef chrono::duration<
		typename common_type<
			Rep1,
			Rep2
		>::type,
		typename detail::ratio_gcd<
			Period1,
			Period2
		>::type
	> type;
};

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
struct common_type<
	chrono::time_point<
		Clock,
		Duration1
	>,
	chrono::time_point<
		Clock,
		Duration2
	>
>
{
	typedef chrono::time_point<
		Clock,
		typename common_type<
			Duration1,
			Duration2
		>::type
	> type;
};

}
}

#endif
