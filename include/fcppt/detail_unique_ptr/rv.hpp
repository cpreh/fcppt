#ifndef FCPPT_UNIQUE_PTR_DETAIL_RV_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DETAIL_RV_HPP_INCLUDED

namespace fcppt
{
namespace unique_ptr_detail
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
