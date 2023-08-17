import type { SkMatrix, Vector } from "@shopify/react-native-skia";
import { MatrixIndex, Skia } from "@shopify/react-native-skia";
import { useMemo } from "react";
import type { SharedValue } from "react-native-reanimated";

export const useMatrixBuffer = () =>
  useMemo(() => [Skia.Matrix(), Skia.Matrix()], []);

const swapMatrixBuffer = (buffer: SkMatrix[], current: SkMatrix) => {
  "worklet";
  const result = buffer.find((m) => m !== current)!;
  result.reset();
  return Skia.Matrix();
};

export const scale = (
  buffer: SkMatrix[],
  output: SharedValue<SkMatrix>,
  input: SkMatrix,
  s: number,
  origin: Vector
) => {
  "worklet";
  output.value = swapMatrixBuffer(buffer, output.value);
  output.value.swap(input);
  output.value.translate(origin.x, origin.y);
  output.value.scale(s, s);
  output.value.translate(-origin.x, -origin.y);
};

export const rotateZ = (
  buffer: SkMatrix[],
  output: SharedValue<SkMatrix>,
  input: SkMatrix,
  theta: number,
  origin: Vector
) => {
  "worklet";
  output.value = swapMatrixBuffer(buffer, output.value);
  output.value.swap(input);
  output.value.translate(origin.x, origin.y);
  output.value.rotate(theta);
  output.value.translate(-origin.x, -origin.y);
};

export const translate = (
  buffer: SkMatrix[],
  output: SharedValue<SkMatrix>,
  input: SkMatrix,
  x: number,
  y: number
) => {
  "worklet";
  output.value = swapMatrixBuffer(buffer, output.value);
  output.value.translate(x, y);
  output.value.concat(input);
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
