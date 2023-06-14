// import React, { useState, useEffect } from "react";
import { ArrowDownOutlined, ArrowUpOutlined } from "@ant-design/icons";
import { Card, Col, Row, Statistic } from "antd";

const App: React.FC = (props: any) => {
  // let [loadState, setLoadState] = useState(true);
  // setLoadState(props.dataAll[1]);
  const seq1=0
  const seq2=1
  const seq3=2
  
  return (
    <>
      <Row gutter={16}>
        <Col span={8}>
          <Card bordered={false}>
            <Statistic
              loading={props.dataAll[1]}
              // loading
              title="光照"
              value={props.dataAll[0][seq1] - props.dataAll[0][seq1 + 6]}
              precision={2}
              valueStyle={{ color: props.dataAll[0][seq1] - props.dataAll[0][seq1 + 6]<=0?"#cf1322":"#3f8600" }}
              prefix={props.dataAll[0][seq1] - props.dataAll[0][seq1 + 6]<=0?<ArrowDownOutlined />:<ArrowUpOutlined />}
              suffix="lx"
            />
          </Card>
        </Col>
        <Col span={8}>
          <Card bordered={false}>
            <Statistic
              loading={props.dataAll[1]}
              // loading
              title="温度"
              value={props.dataAll[0][seq2] - props.dataAll[0][seq2 + 6]}
              precision={2}
              valueStyle={{ color: props.dataAll[0][seq2] - props.dataAll[0][seq2 + 6]<=0?"#cf1322":"#3f8600" }}
              prefix={props.dataAll[0][seq2] - props.dataAll[0][seq2 + 6]<=0?<ArrowDownOutlined />:<ArrowUpOutlined />}
              suffix="°C"
            />
          </Card>
        </Col>
        <Col span={8}>
          <Card bordered={false}>
            <Statistic
              loading={props.dataAll[1]}
              title="湿度"
              value={props.dataAll[0][seq3] - props.dataAll[0][seq3 + 6]}
              precision={2}
              valueStyle={{ color: props.dataAll[0][seq3] - props.dataAll[0][seq3 + 6]<=0?"#cf1322":"#3f8600" }}
              prefix={props.dataAll[0][seq3] - props.dataAll[0][seq3 + 6]<=0?<ArrowDownOutlined />:<ArrowUpOutlined />}
              suffix="%"
            />
          </Card>
        </Col>
      </Row>
    </>
  );
};

export default App;
