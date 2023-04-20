import React, { useState, useEffect } from "react";
import { Progress, Space } from "antd";
// import { render } from "@testing-library/react";
const App: React.FC = () => {
  let [count, setCount] = useState(0); // 定义state:count
  let [count2, setCount2] = useState(0); // 定义state:count
  useEffect(() => {
    // 可以在函数组件内处理生命周期事件，默认情况，每次渲染都会调用该函数
    const t = setInterval(() => {
      setCount(count > 98 ? 98 : count+=4);
      setCount2(count > 98 ? 98 : count2+=4 )
      // if(count>98){count=0}
    }, 200);

    return () => {
      // 每次卸载都执行此函数，清楚定时器
      clearTimeout(t);
    };
  }, []);

  return (
    <>
      {/* <Progress percent={99.9} strokeColor={{ '0%': '#108ee9', '100%': '#87d068' }} /> */}
      {/* <Progress percent={99.9} status="active" strokeColor={{ from: '#108ee9', to: '#87d068' }} /> */}
      <Space wrap>
        <div>
          <Progress
            type="dashboard"
            percent={count}
            format={(count) => `${count} %`}
            size={200}
            strokeColor={{ "0%": "#108ee9", "120%": "#87d068" }}
          />
          <div>
            <center>
              <p className="P2">相对湿度</p>{" "}
            </center>
          </div>
        </div>
        <div>
          <Progress
            type="dashboard"
            percent={count}
            format={(count) => `${count} lx`}
            size={200}
            strokeColor={{ "0%": "#108ee9", "100%": "#87d068" }}
          />
          <div>
            <center>
              <p className="P2">光照强度</p>{" "}
            </center>
          </div>
        </div>
      </Space>
    </>
  );
};

export default App;
