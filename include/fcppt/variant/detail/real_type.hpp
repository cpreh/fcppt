//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_REAL_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_REAL_TYPE_HPP_INCLUDED

#include <fcppt/variant/recursive_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Element
>
struct real_type
{
private:
	typedef variant::recursive<
		Element
	> recursive_type;
public:
	typedef typename boost::mpl::if_<
		boost::mpl::contains<
			Types,
			recursive_type
		>,
		recursive_type,
		Element
	>::type type;
};

}
}
}

#endif
