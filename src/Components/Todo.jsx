import React from "react";

export default function Todo({ todo }) {
  return (
    <>
      <div>
        <label htmlFor="">
          <input type="checkbox" checked={todo.compelete} />
          <span>{todo.name}</span>
        </label>
      </div>
    </>
  );
}
