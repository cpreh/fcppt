#ifndef FCPPT_CONTAINER_ASSIGN_MULTI_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_ASSIGN_MULTI_ARRAY_HPP_INCLUDED

#include <boost/multi_array.hpp>
#include <boost/array.hpp>
#include <cstddef>

namespace fcppt
{
namespace container
{
template<typename T,std::size_t N>
void assign_multi_array(
	boost::multi_array<T,N> &left,
	boost::multi_array<T,N> const &right)
{
	boost::array<typename boost::multi_array<T,N>::size_type,N> a;
	std::copy(
		right.shape(),
		right.shape() + right.num_dimensions(),
		a.begin());
	left.resize(
		a);
	left = right;
}
}
}

#endif
