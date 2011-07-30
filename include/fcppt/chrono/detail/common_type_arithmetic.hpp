//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DETAIL_COMMON_TYPE_ARITHMETIC_HPP_INCLUDED
#define FCPPT_CHRONO_DETAIL_COMMON_TYPE_ARITHMETIC_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
//\cond
#define BOOST_TYPEOF_SILENT
//\endcond
#include <boost/typeof/typeof.hpp>

namespace fcppt
{
namespace chrono
{
namespace detail
{

template<
	typename T,
	typename U,
	typename Enable = void
>
struct common_type_arithmetic
{
};

template<
	typename T,
	typename U
>
struct common_type_arithmetic<
	T,
	U,
	typename boost::enable_if<
		boost::mpl::and_<
			boost::is_arithmetic<
				T
			>,
			boost::is_arithmetic<
				U
			>
		>
	>::type
>
{
private:
	static T m_t();
	static U m_u();
public:
	typedef BOOST_TYPEOF_TPL(true ? m_t() : m_u()) type;
};

}
}
}

#endif
