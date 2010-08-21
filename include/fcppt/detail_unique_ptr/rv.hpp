#ifndef FCPPT_DETAIL_UNIQUE_PTR_RV_HPP_INCLUDED
#define FCPPT_DETAIL_UNIQUE_PTR_RV_HPP_INCLUDED

namespace fcppt
{
namespace detail_unique_ptr
{

template<
	typename T
>
class rv
{
	T &r_;
public:
	explicit rv(
		T &_r
	)
	:
		r_(_r)
	{}

	T *
	operator->()
	{
		return &r_;
	}

	T &
	operator*()
	{
		return r_;
	}
};

}
}

#endif
