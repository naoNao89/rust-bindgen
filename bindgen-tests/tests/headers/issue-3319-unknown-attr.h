// This test verifies that structs with unknown attributes (CXCursor_UnexposedAttr)
// do not generate incorrect layout assertions that would fail at compile time.
// 
// The found_unknown_attr flag is set when bindgen encounters attributes it cannot
// fully interpret, which may affect layout in ways bindgen cannot predict.
// 
// See: https://github.com/rust-lang/rust-bindgen/issues/3319

// __ms_struct__ is an attribute that triggers CXCursor_UnexposedAttr
// and sets found_unknown_attr = true
struct __attribute__((__ms_struct__)) StructWithUnknownAttr {
    int x;
    double y;
};