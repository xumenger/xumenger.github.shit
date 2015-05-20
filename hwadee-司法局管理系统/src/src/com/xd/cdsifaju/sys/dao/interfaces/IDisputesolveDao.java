package com.xd.cdsifaju.sys.dao.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Disputesolve;

public interface IDisputesolveDao {
List<Disputesolve> list();
String add(Disputesolve ds);
}
