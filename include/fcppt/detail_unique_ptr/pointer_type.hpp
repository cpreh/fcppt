#ifndef FCPPT_UNIQUE_PTR_DETAIL_POINTER_TYPE_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DETAIL_POINTER_TYPE_HPP_INCLUDED

namespace fcppt
{
namespace detail_unique_ptr
{
namespace pointer_type_imp
{

template<
	typename U
>
two
test(...);

template<
	typename U
>
one
test(
	typename U::pointer * = 0
);

}  // pointer_type_imp

template<
	typename T
>
struct has_pointer_type
{
	static bool const value =
		sizeof(
			pointer_type_imp::test<T>(0)
		) == 1;
};

namespace pointer_type_imp
{

template<
	typename T, typename D,
	bool = has_pointer_type<D>::value
>
struct pointer_type
{
	typedef typename D::pointer type;
};

template<
	typename T,
	typename D
>
struct pointer_type<T, D, false>
{
	typedef T* type;
};

}  // pointer_type_imp

template<
	typename T,
	typename D
>
struct pointer_type
{
	typedef typename pointer_type_imp::pointer_type<
		T,
		typename boost::remove_reference<D>::type
	>::type type;
};

}  // detail_unique_ptr
}

#endif
