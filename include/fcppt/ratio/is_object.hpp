#ifndef FCPPT_RATIO_IS_OBJECT_HPP_INCLUDED
#define FCPPT_RATIO_IS_OBJECT_HPP_INCLUDED

#include <fcppt/ratio/object.hpp>
#include <fcppt/ratio/int_type.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename T
>
struct is_object
:
boost::false_type
{};

template<
	int_type N,
	int_type D
>
struct is_object<
	object<
		N,
		D
	>
>
:
boost::true_type
{};

}
}

#endif
