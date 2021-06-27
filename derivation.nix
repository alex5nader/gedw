{ stdenv
, meson, ninja, pkg-config
, glfw, glew, xorg }:

stdenv.mkDerivation rec {
  pname = "gedw";
  version = "0.1";

  src = ./.;

  nativeBuildInputs = [ meson ninja pkg-config ];
  buildInputs = [ glfw glew xorg.libX11 ];
}
