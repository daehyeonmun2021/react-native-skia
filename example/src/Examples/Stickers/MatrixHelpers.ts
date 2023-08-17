import type { SkMatrix, Vector } from "@shopify/react-native-skia";
import { Skia, MatrixIndex } from "@shopify/react-native-skia";

export const scale = (input: SkMatrix, s: number, origin: Vector) => {
  "worklet";
  const output = Skia.Matrix();
  output.swap(input);
  output.translate(origin.x, origin.y);
  output.scale(s, s);
  output.translate(-origin.x, -origin.y);
  return output;
};

export const rotateZ = (input: SkMatrix, theta: number, origin: Vector) => {
  "worklet";
  const output = Skia.Matrix();
  output.swap(input);
  output.translate(origin.x, origin.y);
  output.rotate(theta);
  output.translate(-origin.x, -origin.y);
  return output;
};

export const translate = (input: SkMatrix, x: number, y: number) => {
  "worklet";
  const output = Skia.Matrix();
  output.translate(x, y);
  output.concat(input);
  return output;
};

export const toM4 = (m3: SkMatrix) => {
  "worklet";
  const m = m3.get();
  const tx = m[MatrixIndex.TransX];
  const ty = m[MatrixIndex.TransY];
  const sx = m[MatrixIndex.ScaleX];
  const sy = m[MatrixIndex.ScaleY];
  const skewX = m[MatrixIndex.SkewX];
  const skewY = m[MatrixIndex.SkewY];
  const persp0 = m[MatrixIndex.Persp0];
  const persp1 = m[MatrixIndex.Persp1];
  const persp2 = m[MatrixIndex.Persp2];
  return [
    sx,
    skewY,
    persp0,
    0,
    skewX,
    sy,
    persp1,
    0,
    0,
    0,
    1,
    0,
    tx,
    ty,
    persp2,
    1,
  ];
};
