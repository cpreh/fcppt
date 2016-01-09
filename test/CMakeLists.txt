function(
	add_fcppt_test
	PATHNAME
)
	fcppt_utils_add_test(
		"${PATHNAME}"
		${ARGN}
	)
endfunction()


fcppt_utils_link_target(
	fcppt_core
)

fcppt_utils_link_target(
	fcppt_filesystem
)

fcppt_utils_link_target(
	fcppt_log
)

add_fcppt_test(
	absurd
	NO_CODE
)

add_fcppt_test(
	algorithm/all_of
)

add_fcppt_test(
	algorithm/array_init_move
)

add_fcppt_test(
	algorithm/array_push_back
)

add_fcppt_test(
	algorithm/cat_optionals
)

add_fcppt_test(
	algorithm/enum_array_init
)

add_fcppt_test(
	algorithm/find_by_opt
)

add_fcppt_test(
	algorithm/find_if_opt
)

add_fcppt_test(
	algorithm/find_opt
)

add_fcppt_test(
	algorithm/fold
)

add_fcppt_test(
	algorithm/index_of
)

add_fcppt_test(
	algorithm/index_of_enum_array
)

add_fcppt_test(
	algorithm/generate_n
)

add_fcppt_test(
	algorithm/join
)

add_fcppt_test(
	algorithm/key_set
)

add_fcppt_test(
	algorithm/levenshtein
)

add_fcppt_test(
	algorithm/loop
)

add_fcppt_test(
	algorithm/map
)

add_fcppt_test(
	algorithm/map_concat
)

add_fcppt_test(
	algorithm/map_iteration
)

add_fcppt_test(
	algorithm/map_iteration_second
)

add_fcppt_test(
	algorithm/map_optional
)

add_fcppt_test(
	algorithm/optimize_map
	NO_CODE
)

add_fcppt_test(
	algorithm/remove
)

add_fcppt_test(
	algorithm/repeat
)

add_fcppt_test(
	algorithm/sequence_iteration
)

add_fcppt_test(
	algorithm/set_difference
)

add_fcppt_test(
	algorithm/set_intersection
)

add_fcppt_test(
	algorithm/set_union
)

add_fcppt_test(
	algorithm/shift_compare
)

add_fcppt_test(
	assert
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	assert/optional_error
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	assign/make_container
)

add_fcppt_test(
	assign/make_container_opt
)

add_fcppt_test(
	assign/make_map
)

add_fcppt_test(
	bit
)

add_fcppt_test(
	boost_units_value
)

add_fcppt_test(
	cast_to_enum
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	cast/promote
)

add_fcppt_test(
	codecvt
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	const
)

add_fcppt_test(
	container/at_optional
)

add_fcppt_test(
	container/bitfield/comparison
)

add_fcppt_test(
	container/bitfield/empty
)

add_fcppt_test(
	container/bitfield/hash
)

add_fcppt_test(
	container/bitfield/is_subset_eq
)

add_fcppt_test(
	container/bitfield/object
)

add_fcppt_test(
	container/bitfield/operators
)

add_fcppt_test(
	container/bitfield/underlying_value
)

add_fcppt_test(
	container/data
)

add_fcppt_test(
	container/enum_array
)

add_fcppt_test(
	container/find_opt
)

add_fcppt_test(
	container/find_opt_mapped
)

add_fcppt_test(
	container/get_or_insert
)

add_fcppt_test(
	container/grid/apply
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/at_optional
)

add_fcppt_test(
	container/grid/clamped_min
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/clamped_sup
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/clamped_sup_signed
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/comparison
)

add_fcppt_test(
	container/grid/fill
)

add_fcppt_test(
	container/grid/in_range
)

add_fcppt_test(
	container/grid/map
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/moore_neighbors
)

add_fcppt_test(
	container/grid/neumann_neighbors
)

add_fcppt_test(
	container/grid/object
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/pos_range
)

add_fcppt_test(
	container/grid/pos_ref_range
)

add_fcppt_test(
	container/grid/resize_preserve
)

add_fcppt_test(
	container/grid/resize_preserve_init
)

add_fcppt_test(
	container/grid/spiral_range
)

add_fcppt_test(
	container/index_map
)

add_fcppt_test(
	container/maybe_back
)

add_fcppt_test(
	container/maybe_front
)

add_fcppt_test(
	container/raw_vector
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/tree/child_position
)

add_fcppt_test(
	container/tree/copy
)

add_fcppt_test(
	container/tree/depth
)

add_fcppt_test(
	container/tree/equal
)

add_fcppt_test(
	container/tree/level
)

add_fcppt_test(
	container/tree/map
)

add_fcppt_test(
	container/tree/move
)

add_fcppt_test(
	container/tree/pre_order
)

add_fcppt_test(
	container/tree/print
)

add_fcppt_test(
	container/tree/swap
)

add_fcppt_test(
	cyclic_iterator
)

add_fcppt_test(
	either/apply
)

add_fcppt_test(
	either/bind
)

add_fcppt_test(
	either/cat
)

add_fcppt_test(
	either/from_optional
)

add_fcppt_test(
	either/map
)

add_fcppt_test(
	either/match
)

add_fcppt_test(
	either/object
)

add_fcppt_test(
	either/success_opt
)

add_fcppt_test(
	endianness
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	enum_range
)

add_fcppt_test(
	extract_from_string
)

add_fcppt_test(
	filesystem/remove_extension
	LINK_LIBS
		"${fcppt_filesystem_TARGET}"
)

add_fcppt_test(
	function
)

add_fcppt_test(
	homogenous_pair
)

add_fcppt_test(
	insert_to_string
)

add_fcppt_test(
	int_range
)

add_fcppt_test(
	io/read_write
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	io/stream_to_string
)

add_fcppt_test(
	io/raw_container_source
)

add_fcppt_test(
	literal
)

add_fcppt_test(
	log/context_transfer
	LINK_LIBS
		 "${fcppt_core_TARGET};${fcppt_log_TARGET}"
)

add_fcppt_test(
	math/at_c
)

add_fcppt_test(
	math/bresenham
)

add_fcppt_test(
	math/ceil_div
)

add_fcppt_test(
	math/circle
)

add_fcppt_test(
	math/binary_vectors
)

add_fcppt_test(
	math/interpolation
)

add_fcppt_test(
	math/interval_distance
)

add_fcppt_test(
	math/is_power_of_2
)

add_fcppt_test(
	math/vector
)

add_fcppt_test(
	math/units
)

add_fcppt_test(
	math/util
)

add_fcppt_test(
	math/box/center
)

add_fcppt_test(
	math/box/comparison
)

add_fcppt_test(
	math/box/contains
)

add_fcppt_test(
	math/box/contains_point
)

add_fcppt_test(
	math/box/corner_points
)

add_fcppt_test(
	math/box/distance
)

add_fcppt_test(
	math/box/extend
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	math/box/init_dim
)

add_fcppt_test(
	math/box/init_max
)

add_fcppt_test(
	math/box/intersection
)

add_fcppt_test(
	math/box/shrink
)

add_fcppt_test(
	math/box/stretch_absolute
)

add_fcppt_test(
	math/box/stretch_relative
)

add_fcppt_test(
	math/box/structure_cast
)

add_fcppt_test(
	math/dim/componentwise_equal
)

add_fcppt_test(
	math/dim/construct
)

add_fcppt_test(
	math/dim/fill
)

add_fcppt_test(
	math/dim/has_dim
	NO_CODE
)

add_fcppt_test(
	math/dim/hash
)

add_fcppt_test(
	math/dim/input
)

add_fcppt_test(
	math/dim/is_quadratic
)

add_fcppt_test(
	math/dim/map
)

add_fcppt_test(
	math/dim/narrow_cast
)

add_fcppt_test(
	math/dim/to_signed
)

add_fcppt_test(
	math/dim/to_unsigned
)

add_fcppt_test(
	math/matrix/access
)

add_fcppt_test(
	math/matrix/adjugate
)

add_fcppt_test(
	math/matrix/at_c
)

add_fcppt_test(
	math/matrix/delete_row_and_column
)

add_fcppt_test(
	math/matrix/determinant
)

add_fcppt_test(
	math/matrix/exponential_pade
)

add_fcppt_test(
	math/matrix/has_dim
	NO_CODE
)

add_fcppt_test(
	math/matrix/hash
)

add_fcppt_test(
	math/matrix/infinity_norm
)

add_fcppt_test(
	math/matrix/inverse
)

add_fcppt_test(
	math/matrix/is_matrix
	NO_CODE
)

add_fcppt_test(
	math/matrix/logarithm
)

add_fcppt_test(
	math/matrix/multiply
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	math/matrix/operators
)

add_fcppt_test(
	math/matrix/rotation_axis
)

add_fcppt_test(
	math/matrix/rotation_x
)

add_fcppt_test(
	math/matrix/scaling
)

add_fcppt_test(
	math/matrix/structure_cast
)

add_fcppt_test(
	math/matrix/transform_direction
)

add_fcppt_test(
	math/matrix/transform_point
)

add_fcppt_test(
	math/matrix/translation
)

add_fcppt_test(
	math/matrix/transpose
)

add_fcppt_test(
	math/matrix/view
)

add_fcppt_test(
	math/vector/arithmetic
)

add_fcppt_test(
	math/vector/ceil_div_signed
)

add_fcppt_test(
	math/vector/comparison
)

add_fcppt_test(
	math/vector/distance
)

add_fcppt_test(
	math/vector/fill
)

add_fcppt_test(
	math/vector/hash
)

add_fcppt_test(
	math/vector/input
)

add_fcppt_test(
	math/vector/map
)

add_fcppt_test(
	math/vector/null
)

add_fcppt_test(
	math/vector/raw_view
)

add_fcppt_test(
	math/vector/structure_cast
)

add_fcppt_test(
	math/vector/swap
)

add_fcppt_test(
	math/vector/to_signed
)

add_fcppt_test(
	math/vector/to_unsigned
)

add_fcppt_test(
	math/vector/unit
)

add_fcppt_test(
	math/vector/view_storage
)

add_fcppt_test(
	mpl/all_of
	NO_CODE
)

add_fcppt_test(
	mpl/append
	NO_CODE
)

add_fcppt_test(
	mpl/ceil_div
	NO_CODE
)

add_fcppt_test(
	mpl/enum_range
	NO_CODE
)

add_fcppt_test(
	move_if_rvalue
)

add_fcppt_test(
	optional/alternative
)

add_fcppt_test(
	optional/apply
)

add_fcppt_test(
	optional/assign
)

add_fcppt_test(
	optional/bind
)

add_fcppt_test(
	optional/casts
)

add_fcppt_test(
	optional/combine
)

add_fcppt_test(
	optional/compare
)

add_fcppt_test(
	optional/copy_value
)

add_fcppt_test(
	optional/deref
)

add_fcppt_test(
	optional/filter
)

add_fcppt_test(
	optional/from
)

add_fcppt_test(
	optional/from_pointer
)

add_fcppt_test(
	optional/general
)

add_fcppt_test(
	optional/join
)

add_fcppt_test(
	optional/map
)

add_fcppt_test(
	optional/maybe
)

add_fcppt_test(
	optional/maybe_multi
)

add_fcppt_test(
	optional/maybe_void
)

add_fcppt_test(
	optional/maybe_void_multi
)

add_fcppt_test(
	optional/move
)

add_fcppt_test(
	optional/reference
)

add_fcppt_test(
	optional/to_exception
)

add_fcppt_test(
	random/wrapper/uniform_container
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	reference_wrapper
)

add_fcppt_test(
	reference_wrapper_to_base
)

add_fcppt_test(
	runtime_enum
)

add_fcppt_test(
	scoped_state_machine
)

add_fcppt_test(
	shared_ptr
)

add_fcppt_test(
	signal/simple
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	signal/unregister
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	strong_typedef
)

add_fcppt_test(
	truncation_check_cast
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	type_traits/function_pointer_to_reference
	NO_CODE
)

add_fcppt_test(
	type_traits/generate_has_member_function
	NO_CODE
)

add_fcppt_test(
	type_traits/generate_has_type
	NO_CODE
)

add_fcppt_test(
	type_traits/is_iterable
	NO_CODE
)

add_fcppt_test(
	type_traits/is_iterator
	NO_CODE
)

add_fcppt_test(
	type_traits/iterator_category
	NO_CODE
)

add_fcppt_test(
	unique_ptr
)

add_fcppt_test(
	variant/apply_movable
)

add_fcppt_test(
	variant/apply_nonconst
)

add_fcppt_test(
	variant/apply_prvalue
)

add_fcppt_test(
	variant/assign
)

add_fcppt_test(
	variant/compare
)

add_fcppt_test(
	variant/equal
)

add_fcppt_test(
	variant/exception
)

add_fcppt_test(
	variant/get_exn
)

add_fcppt_test(
	variant/holds_type
)

add_fcppt_test(
	variant/less
)

add_fcppt_test(
	variant/match
)

add_fcppt_test(
	variant/move
)

add_fcppt_test(
	variant/output
)

add_fcppt_test(
	variant/to_optional
)

add_fcppt_test(
	variant/to_optional_ref
)

add_fcppt_test(
	variant/variadic
	NO_CODE
)
