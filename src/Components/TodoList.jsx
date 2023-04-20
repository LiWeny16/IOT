import React from "react";
import Todo from "./Todo.jsx";
// import Component from "./component.jsx";
export default function TodoList({ todos }) {
  return todos.map((todo) => {
    return (
      <>
        <Todo key={todo.id} todo={todo} />
        {/* <Component /> */}
      </>
    );
  });
}
